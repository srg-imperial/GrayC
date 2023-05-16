sudo apt remove frama-c -y -f
sudo apt remove frama-c-base -y -f
echo ">> Try to get newer version of frama-c"
sudo add-apt-repository ppa:avsm/ppa
sudo apt update
sudo apt-get install ocaml ocaml-native-compilers graphviz \
             libzarith-ocaml-dev libfindlib-ocaml-dev \
             liblablgtksourceview2-ocaml-dev liblablgtk2-gnome-ocaml-dev -y -f
sudo apt remove opam -f -y
sudo apt install opam -f -y
opam --version
opam update
echo ">> Shall be opam 2.0.0 or above for Frama-c"
opam init -y
eval `opam config env`
opam install why3 why3-ide alt-ergo
why3 --version
alt-ergo -version
echo ">> Try to install ocaml"
sudo apt remove ocaml
# environment setup
opam init
eval `opam env`
# install given version of the compiler
opam switch create 4.10.0
eval `opam env`
# check you got what you want
which ocaml
ocaml -version
echo ">> There is a known issue with OCaml 4.05.0 and ocamlfind 1.8.1"
opam install alt-ergo.2.2.0
opam install depext -y
opam depext frama-c -y
#opam install frama-c -y ==> till know bugs with Ocaml are solved
opam install frama-c.25.0 -y
eval $(opam config env)
