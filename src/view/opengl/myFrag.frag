#version 130

in vec3 vs_out_col;

out vec4 fs_out_col;

void main()
{
    vec3 col = vec3(0.f, 1.f, 0.f);
    if (vs_out_col.x > 0.1f)
    {
        col = vec3(1.f, 0.f, 0.f);
    }

    col *= (vs_out_col.x > 0.1f)?(vs_out_col.x):(vs_out_col.x + 0.7f);

    fs_out_col = vec4(col, 1.f);
}
