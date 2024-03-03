# cub3d project at 42Perpignan
## by odiachen & mjochum
> Alright, listen up folks, 'cause we're diving into the world of cub3D, alright? This ain't your grandma's project. No sir. This is like Wolfenstein 3D on steroids. We're talking RayCasting, we're talking miniLibX, we're talking getting lost in a maze and loving every minute of it.
> So, picture this: you got your C programming skills on point, you're diving deep into graphics design, and you're like, "Let's make something epic." That's cub3D, baby. It's like building your own virtual world, brick by brick, pixel by pixel. And let me tell ya, it's a wild ride from start to finish.
> We're talking smooth window management, we're talking wall textures that'll blow your mind, and we're talking bonus features that'll make you jump outta your seat. Wall collisions? Check. Animated sprites? You betcha. Doors that open and close? Hell yeah.
[^1]Bill Burr, on cub3d.

## todos, or what we thought would be a good workflow
### getting ready for the bonuses (boni ?[^2])
The bonus can be divided in two categories. The easy ones, and the ones that require "new" code.
|easy| |hard| |
|:---|-|:--:|-:|
|wall colllision|cast a fixed ray, or, "try" to step one way and check if it's a valid space.|animated sprite|Oof. First, define what a sprite is. We focused on "images with an array of images in it", "transparency" and "animated". Transparency did not work out with how we implemented it.|
|doors which can open and close|same as wall collision, except triggered by a key press, and changes state of map if a door is found|minimap system|initialise an image. fill it out with little squares. Every frame, draw player position on top of it.|
|rotate pov with mouse|change player angle on x-axis mouse movement|||


implement mlx
define structures
initialize with error management in mind (map error, imput error, mapdata error, map validation)
mlx loop and frame rendering
raycasting
raycasting mini

## pitfalls, or how problems for future me really annoyed future me
error management and segfaults

[^1] not really but we had no hook for our readme
[^2] thank you, i'll be here all day.
