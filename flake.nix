{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }:

    utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };

        c_universal_flags = "-DLOCAL -std=c++2b -Wall -Wextra -Wshadow -Wno-sign-conversion";
        c_debug_flags = "-DDEBUG -D_GLIBCXX_ASSERTIONS -fsanitize=address,undefined -g -ggdb3";
        c_heavy_debug_flags = "-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC";

        script_cpp_compile = pkgs.writeShellScriptBin "c" ''
          g++ ${c_universal_flags} -I"$DIR/include" -O2 "$1.cpp" -o "$1"
        '';

        script_cpp_debug = pkgs.writeShellScriptBin "d" ''
          g++ ${c_universal_flags} ${c_debug_flags} -I"$DIR/include" "$1.cpp" -O0 -o "$1"
        '';

        script_cpp_debug_heavy = pkgs.writeShellScriptBin "dh" ''
          g++ ${c_universal_flags} ${c_debug_flags} ${c_heavy_debug_flags} -I"$DIR/include" "$1.cpp" -O0 -o "$1"
        '';

        script_cpp_run = pkgs.writeShellScriptBin "cr" ''
          c "$1" && "./$1"
        '';

        script_cpp_run_debug = pkgs.writeShellScriptBin "dr" ''
          d "$1" && "./$1"
        '';

        script_stress = pkgs.writeShellScriptBin "stress" ''
          echo "Compiling..."
          c "$1"

          for ((i=1; i<=$2; i++)); do
            ./$1 gen $i > in.txt
            ./$1 brute < in.txt > ans.txt
            ./$1 < in.txt > out.txt
                
            if ! cmp -s out.txt ans.txt; then
              echo -e "\n\033[31mWA on iteration $i\033[0m\n"
                  
              echo -e "\033[33m--- Input ---\033[0m"
              cat in.txt
              echo ""

              echo -e "\033[33m--- (Expected, Got) ---\033[0m"
              icdiff ans.txt out.txt | head -n 50

              break
            fi
            echo -ne "Passed $i\r"
          done
        '';
      in
      {
        devShells.default = pkgs.mkShellNoCC {
          packages = with pkgs; [
            gcc14
            pypy3
            jdk21
            icdiff
            clang-tools

            script_cpp_compile
            script_cpp_debug
            script_cpp_debug_heavy
            script_cpp_run
            script_cpp_run_debug
            script_stress
          ];

          shellHook = ''
            export DIR=$PWD
          '';
        };
      }
    );
}
