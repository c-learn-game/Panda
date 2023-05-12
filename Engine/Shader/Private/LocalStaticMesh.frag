#version 400 core


in vec3 FragNormal;
in vec4 FragColor;
in vec4 FragUV0;

uniform sampler2D ContainerTex;

out vec4 PixelColor;

void main()
{
    PixelColor = texture(ContainerTex, FragUV0.xy);
}