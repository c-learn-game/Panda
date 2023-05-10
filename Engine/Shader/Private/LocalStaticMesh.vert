#version 400 core

layout(location=0) in vec4 VertPosition;
layout(location=1) in vec4 VertNormal;
layout(location=2) in vec4 VertColorIndex0;
layout(location=2) in vec4 VertColorIndex1;
layout(location=2) in vec4 VertColorIndex2;
layout(location=5) in vec4 VertUVIndex0;

in vec4 CustomDataIndex0;
in vec4 CustomDataIndex1;

out vec3 FragNormal;
out vec4 FragColor;
out vec4 FragUVIndex0;

void main()
{
    gl_Position = VertPosition;
    FragNormal = VertNormal.xyz;
    FragColor = VertColorIndex0;
    FragUVIndex0 = VertUVIndex0;
    //[%s]
}