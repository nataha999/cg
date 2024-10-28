using Assimp;
using OpenTK.Mathematics;
using System.Drawing.Imaging;
using System.Drawing;
using OpenTK.Graphics.OpenGL;
using TextureWrapMode = OpenTK.Graphics.OpenGL.TextureWrapMode;

namespace _1
{
    public class MaterialLoader
    {
        private int[] texId = [];
        private bool texLoaded = false;

        public void LoadMaterialTextures(Material material)
        {
            texId = new int[material.GetMaterialTextureCount(TextureType.Diffuse)];
            texLoaded = true;
            for (int i = 0; i < material.GetMaterialTextureCount(TextureType.Diffuse); i++)
            {
                TextureSlot textureSlot;
                if (material.GetMaterialTexture(TextureType.Diffuse, i, out textureSlot))
                {
                    if (File.Exists(textureSlot.FilePath))
                    {
                        int texId = GL.GenTexture();
                        GL.BindTexture(TextureTarget.Texture2D, texId);

                        using (Bitmap bitmap = new Bitmap(textureSlot.FilePath))
                        {
                            BitmapData data = bitmap.LockBits(new Rectangle(0, 0, bitmap.Width, bitmap.Height), ImageLockMode.ReadOnly, System.Drawing.Imaging.PixelFormat.Format32bppArgb);
                            GL.TexImage2D(TextureTarget.Texture2D, 0, PixelInternalFormat.Rgba, data.Width, data.Height, 0, OpenTK.Graphics.OpenGL.PixelFormat.Bgra, PixelType.UnsignedByte, data.Scan0);
                            bitmap.UnlockBits(data);
                        }

                        GL.GenerateMipmap(GenerateMipmapTarget.Texture2D);
                        GL.TexParameter(TextureTarget.Texture2D, TextureParameterName.TextureWrapS, (int)TextureWrapMode.Repeat);
                        GL.TexParameter(TextureTarget.Texture2D, TextureParameterName.TextureWrapT, (int)TextureWrapMode.Repeat);
                        GL.TexParameter(TextureTarget.Texture2D, TextureParameterName.TextureMinFilter, (int)TextureMinFilter.Linear);
                        GL.TexParameter(TextureTarget.Texture2D, TextureParameterName.TextureMagFilter, (int)TextureMagFilter.Linear);

                        this.texId[i] = texId;
                    }
                }
            }
        }

        public void ApplyMaterial(Material material, int index)
        {
            Color4 ambientColor = Color4DToColor4(material.ColorAmbient);
            Color4 diffuseColor = Color4DToColor4(material.ColorDiffuse);
            Color4 specularColor = Color4DToColor4(material.ColorSpecular);
            float shininess = material.Shininess;
            GL.Material(MaterialFace.FrontAndBack, MaterialParameter.Ambient, ambientColor);
            GL.Material(MaterialFace.FrontAndBack, MaterialParameter.Diffuse, diffuseColor);
            GL.Material(MaterialFace.FrontAndBack, MaterialParameter.Specular, specularColor);
            GL.Material(MaterialFace.FrontAndBack, MaterialParameter.Shininess, shininess);
            if (texLoaded && material.GetMaterialTexture(TextureType.Diffuse, index, out TextureSlot textureSlot))
            {
                GL.ActiveTexture(TextureUnit.Texture0);
                GL.BindTexture(TextureTarget.Texture2D, texId[index]);
            }
        }

        private Color4 Color4DToColor4(Color4D color4d)
        {
            Color4 color4 = new()
            {
                A = color4d.A,
                R = color4d.R,
                G = color4d.G,
                B = color4d.B
            };
            return color4;
        }
    }
}