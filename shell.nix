{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    clang-tools
    cmake
    pkg-config
    bear
  ];
  
  buildInputs = with pkgs; [
    gcc
    raylib
    glfw
  ];
  
  shellHook = ''
    echo "Environment Swapped"
  '';
}
