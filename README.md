# Goals
It’s time to create a basic computer graphics project!


We are going to use the school graphical library: the MiniLibX! This library was
developed internally and includes basic necessary tools to open a window, create images
and deal with keyboard and mouse events.


This will be the opportunity to get familiar with the MiniLibX, to discover the
basics of graphics programming, especially how to place points in space, join them
and how to see the scene from a specific viewpoint.

## Rules

This project is about creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges).

<table>
    <tbody>
        <tr>
            <td align="center">Program name </td>
            <td>fdf</td>
        </tr>
        <tr>
            <td align="center">Turn in files</td>
            <td>Makefile, *.h, *.c</td>
        </tr>
        <tr>
            <td align="center">Makefile</td>
            <td>NAME, all, clean, fclean, re</td>
        </tr>
        <tr>
            <td align="center">Arguments </td>
            <td>A file in format *.fdf</td>
        </tr>
        <tr>
            <td align="center">External functs.</td>
            <td>
			<ul>open, close, read, write, malloc, free, perror, strerror, exit</ul>
			<ul>All functions of the math library (-lm compiler option, man man 3 math)</ul>
			<ul>All functions of the MiniLibX</ul>
			<ul>ft_printf and any equivalent YOU coded</ul>
			</td>
        </tr>
        <tr>
            <td align="center">Libft authorized </td>
            <td>Yes</td>
        </tr>
        <tr>
            <td align="center">Description </td>
            <td>This project is about creating a simple wireframe model of a landscape.</td>
        </tr>
    </tbody>
</table>

- You must use the MiniLibX. Either the version available on the school machines, or installing it using its sources.
- You have to turn in a Makefile which will compile your source files. It must not relink.
- Your program has to represent the model in isometric projection.
- The coordinates of the landscape are stored in a .fdf file passed as a parameter to your program. Here is an example:


- Each number represents a point in space:
	- The horizontal position corresponds to its axis.
	- The vertical position corresponds to its ordinate.
	- The value corresponds to its altitude.


- Your program has to display the image in a window.
- The management of your window must remain smooth (changing to another window, minimizing, and so forth).
- Pressing ESC must close the window and quit the program in a clean way.
- Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
- The use of the images of the MiniLibX is mandatory.


  ### Forbidden

	- Global variables
  

## Bonus

- Include one extra projection (such as parallel or conic)
- Zoom in and out.
- Translate your model.
- Rotate your model.
- Add one more bonus of your choice.

 
# Result :slot_machine:


# Usage

``make``

Run the program with 
```bash
./
```

Return exemple:

```text
....
```

# Advance usage

``make``

Run the program

```bash
./
```

Return exemple:

```text
....
```
