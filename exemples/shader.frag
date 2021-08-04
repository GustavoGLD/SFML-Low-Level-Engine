uniform float intensity;

void main()
{
    gl_FragColor = gl_Color * vec4(intensity, 1.0, 1.0, 1.0);
}