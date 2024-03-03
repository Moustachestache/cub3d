# cub3d project at 42Perpignan
## by odiachen & mjochum
> Alright, listen up folks, 'cause we're diving into the world of cub3D, alright? This ain't your grandma's project. No sir. This is like Wolfenstein 3D on steroids. We're talking RayCasting, we're talking miniLibX, we're talking getting lost in a maze and loving every minute of it.
> So, picture this: you got your C programming skills on point, you're diving deep into graphics design, and you're like, "Let's make something epic." That's cub3D, baby. It's like building your own virtual world, brick by brick, pixel by pixel. And let me tell ya, it's a wild ride from start to finish.
> We're talking smooth window management, we're talking wall textures that'll blow your mind, and we're talking bonus features that'll make you jump outta your seat. Wall collisions? Check. Animated sprites? You betcha. Doors that open and close? Hell yeah.

- Bill Burr, on cub3d. [^1]

## todos, or what we thought would be a good workflow
### getting ready for the bonuses. (bonii ?)[^2]
|easy peasy|reduce reuse recycle code|hard-ey sad-ey|forced to use neurons oowie|
|:--:|-|:--:|:-|
|wall collision|cast a fixed ray - or "try" to step one way - and check if player lands in a valid space.|animated sprite|Oof. First, define what a sprite is. We chose "an image with an array of images in it", "transparent" and "animated". The heavy lifting is done at initialisation: Create 4 images. fill each one with parts of the sprite. Alternate between the images depending on the current frame when rendering.|
|doors which can open and close|same as wall collision, except triggered by a key press, and changes state of map if a door is found|minimap system|initialise an image. fill it out with little squares. Every frame, draw player position on top of it.|
|rotate pov with mouse|change player angle on x-axis mouse movement|||

### implementation of mlx
Nothing fancy. Except the use of mlx_loop_hook that calls the rendering function (ft_render), allowing us to render independantly of ft_keyhooks (which is what I did in fdf). We generate frames whenever possible. Whenever we press a key, a value is changed.

### defining structures
s_image		- mlx image structure.

s_pixel		- pixel coordinates and pixel colour.

s_vars		- our grab-bag of variables. Has most non-map related images, mlx pointers, frame timer, fps counter, toggles and error management.

s_map		- our map information. Also contains textures for said map (map->texture and map->stexture)

s_player	- player information (start point, position and angle of view)

s_camera	- our camera for raycasting.
initialize with error management in mind (map error, imput error, mapdata error, map validation)

### map initialisation
it goes:

1 -> read the pre-map data: textures, colours etc. As you do, check they are valid.

2 -> read map info. No checks yet except finding starting point and confirming valid characters ('1', '0', ' ' and doors / sprites). Save map maxwidth and maxheight.

3 -> validate map info. Work on a map duplicate, where every line is initialised as an array of spaces that is the maximum width.Check the map >= 3 in width and height.
Starting from player start point, move in all directions and check if sides (n, s, ea and we) are 0 or 1. if 0 validates that there are either 0 or 1 around. If space, increment error counter.

### raycasting
> from player position, start calculating with math(tm) and once you find a '1' you have a distance. Easy.

_A person that hasn't coded the raycasting algorithm._ [^3]

### raycasting mini
> same but for opening doors

_same idiot as above_ [^4]

### personal bonuses, or "I never once asked if I should"
- Frame Timer - srcs/ft_frame.c	- simple unix time where we check the difference every frame. If difference (currenttime - oldtime) is 1, increment frame counter. Save currenttime as oldtime.
- FPS counter	- srcs/ft_frame.c - with the frame timer (ever one second, we increment a counter up to a maximum of 3, allowing us to chose which sprite to render), we can count how many frame are generated in a second. The downside being, the FPS how many frame were generated the previous second.
- FPS graph - srcs/ft_render_graphfps.c- since the data exists, we write it in an image that rewrites on itself with a -1 offset, so it looks like it's moving left. Luckily the function that draws an image into an image works natively with a negative offset. 
- Transparency - - when you draw a pixel, return if the pixel is the defined transparency color. In our case it's '#00ff00'

### pitfalls, or how problems for future me really annoyed future me
Turns out you cant just escape the program when you encounter an error, especially in the "initialisation" phase.

With that in mind, there are parts of the code where we used an int to define the error status. We increment it, and write out which error occured in the terminal, and we quit the program before initialising the mlx loop.

This allows us to clear out the memory and to be sure all allocated buffers can be tidied up (looking at you ft_split you rat bastard).

[^1]: not really but we had no hook for our readme
[^2]: thank you, i'll be here all day.
[^3]: that would be mjochum.
[^4]: see [^3].
