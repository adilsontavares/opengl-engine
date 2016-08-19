uniform sampler2D mainTexture;

in vec3 fragmentColor;
in vec2 uv;

out vec3 color;

void main()
{
	color = texture(mainTexture, uv).rgb;
}