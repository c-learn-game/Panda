#version 400 core


in vec3 FragNormal;
in vec4 FragColor;
in vec4 FragUVIndex0;

uniform sampler2D ContainerTex;

out vec4 PixelColor;

void main()
{
    vec2 UV0 = FragUVIndex0.xy;
    vec2 UV1 = FragUVIndex0.zw;
    PixelColor = texture(ContainerTex, UV0);
}