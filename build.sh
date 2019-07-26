# /bin/bash

PROMPT="\
Press [1] to Build\n\
Press [2] to Install\n\
Press [3] to Clean\n"

echo -e $PROMPT
read keypress

case $keypress in
    "1") echo "Building"; 
        mkdir -p build;
        cd build/;
        cmake ..;
        make;
        echo "Creating Documentation";
        make doc;;

    
    "2") echo "Building"; 
        mkdir -p build;
        cd build/;
        cmake ..;
        make;
        echo "Creating Documentation"
        make doc;
        echo "Installing";
        make install-lib;;

    
    "3") echo "Cleaning";
        cd build/;
        make clean-all;
        cd ..;
        rm -rf build;;


    *)   echo "Command not Valid";;
esac