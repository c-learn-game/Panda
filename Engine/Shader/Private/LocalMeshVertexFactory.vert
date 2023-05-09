#version 400 core

layout(location=0) in vec4 VertPosition;
layout(location=1) in vec4 VertNormal;
layout(location=2) in vec4 VertColor0;
layout(location=3) in vec4 VertColor1;
layout(location=4) in vec4 VertColor2;

uniform vec4 CustomData0;
uniform vec4 CustomData1;

out vec4 FragColor;

void main()
{
    gl_Position = VertPosition;
    FragColor = VertColor1;
    // CustomData数据插入
    // [custom vert shader %s]
}