#version 400 core


in vec3 FragNormal;
in vec4 FragColor;
in vec4 FragUVIndex0;

uniform sampler2D ContainerTex;
uniform sampler2D ColorTex;

out vec4 PixelColor;

void main()
{
    vec2 UV0 = FragUVIndex0.xy;
    vec2 UV1 = FragUVIndex0.zw;
    vec4 BoxColor = texture(ContainerTex, UV0);
    vec4 BlendColor = texture(ColorTex, UV0);
    PixelColor = 0.8 * BoxColor + 0.2 * BlendColor;
}