#version 130

in vec3 vs_out_col;

out vec4 fs_out_col;

uniform int coloring;

void main()
{
        if (coloring == 0)
        {
                fs_out_col = vec4(vs_out_col, 1);
        }
        else
        {
                vec3 col = vec3(0, 1, 0);
                if (vs_out_col.x > 0.1)
                {
                        col = vec3(1, 0, 0);
                }

                col *= (vs_out_col.x > 0.1)?(vs_out_col.x):(vs_out_col.x + 0.7);

                fs_out_col = vec4(col, 1);
        }
}
