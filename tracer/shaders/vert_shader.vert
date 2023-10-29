#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color_a;
layout (location = 2) in vec2 text;

out vec3 colorFrag;
out vec2 TexCoord;


void main()
{
    gl_Position  = vec4(position, 1.0);
    colorFrag = color_a; 
    TexCoord = vec2(text.x,text.y); 
}