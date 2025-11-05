# furry framework
furry framework is a game framework designed to be a game engine originally but now i dont want that anymore so i changed the name to furry framework and also that starts with the same letter so it all works out in the end yay  
it is built using c99  

## contribution
to contribute, open up a pull request on github  
there are some rules for contributed code:
- language must not be c++
- when using c, it must be c99
- you must not need more than some very basic dependencies (preferrably none)

## license
this project is licensed under the LGPLv3 copyleft,  
for more information, see [here](LICENSE.LGPL)

## usage
to use this framework in your project, its pretty "simpleh  
heres some steps (there are 2 routes you can take: with and without git):
- USING GIT:
    - in your project root:
        - run `git submodule add https://github.com/viylouu/furry-framework.git`
        - run `git mv furry-framework furry`
    - then, do the `GENERAL` steps
- WITHOUT GIT:
    - clone the repo `git clone https://github.com/viylouu/furry-framework.git`
    - in your project, copy the `furry-engine` folder over to it
    - rename `furry-framework`to `furry`
    - then, do the `GENERAL` steps
- GENERAL:
    - copy a few files and folders from `furry` to your project root:
        - `build.sh`
        - `data`

## building
when building, you can do one of 2 things:
- build your own project
- build an example

to build an example:
- in the `furry-framework` folder (or the `furry` folder) you *definitely* cloned already:
    - run `./build.sh EXAMPLE_NAME <options>`
        - for example, running the `window` example would be `./build.sh window`
> NOTE:  
> here are some options for you  
> -t   builds as a test using -O0 (or tcc)  
> -w   builds for windows (NOT NEEDED ON WINDOWS)  

to build your own project:
- in your project root:
    - run `./build.sh <options>`
