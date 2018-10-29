# wolf3d

This is 3D graphically “realistic” representation that we could have from
inside a maze in a subjective view. This representation useses
Ray-Casting principles. SDL2 is used as graphical library here.

# usage
On Mac Os
```bash
git clone https://github.com/iradchenua/wolf3d.git somewhere/wolf3d
cd wolf3d
make
./wolf3d tests/some_map
enjoy ^^^
```

# map definition
The map file is a simple text file with following lines: <br />
h w <br />
B00 ..... B0w-1 <br />
.    .    . <br />
.     Bij . <br />
.      .  . <br />
Bh-10 ..... Bh-1w-1 <br />
where h - height of the map, 0 < h <= 40, w - widht of the map, 0 < w <= 40 <br />
Bij is in {0,..,11,x} 0 <= i < h, 0 <= j < w <br />
x is player <br />
number is box type 0 - no box, 11 - special box with differrent 4 sides <br />
to see other wall type look textures/(type - 1).bmp <br />
To move in the map use arrows, left shift to acceleration <br />
