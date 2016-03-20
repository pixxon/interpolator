#version 130

in vec3 vs_out_col;

out vec4 fs_out_col;

void main()
{
    vec3 col = clamp(vs_out_col, vec3(1, 0, 0), vec3(0, 1, 0));
    fs_out_col = vec4(col, 1);
}
