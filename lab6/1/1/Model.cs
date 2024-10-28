using Assimp;
using OpenTK.Graphics.OpenGL;
using OpenTK.Mathematics;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1
{
    public class Model
    {
        private Scene scene = new();
        private int[] displayLists = [];
        private MaterialLoader materialLoader = new();


        
        public void LoadModel(string filePath)
        {
            AssimpContext importer = new AssimpContext();
            scene = importer.ImportFile(
                filePath, 
                PostProcessSteps.FlipUVs);
            importer.Dispose();
            LoadTextures();
            CreateDisplayLists();
        }

        private void CreateDisplayLists()
        {
            int meshCount = scene.MeshCount;
            displayLists = new int[meshCount];

            for (int i = 0; i < meshCount; i++)
            {
                Mesh mesh = scene.Meshes[i];

                displayLists[i] = GL.GenLists(1);
                GL.NewList(displayLists[i], ListMode.Compile);
                materialLoader.ApplyMaterial(scene.Materials[mesh.MaterialIndex], i);

                Vector3[] vertices = AssimpVectroToOpenTKVector([.. mesh.Vertices]);
                Vector3[] normals = AssimpVectroToOpenTKVector([.. mesh.Normals]);
                Vector3[] textureCoordinates = AssimpVectroToOpenTKVector([.. mesh.TextureCoordinateChannels[0]]);

                if (mesh.Faces[0].IndexCount % 3 == 0)
                    GL.Begin(OpenTK.Graphics.OpenGL.PrimitiveType.Triangles);
                else
                    GL.Begin(OpenTK.Graphics.OpenGL.PrimitiveType.Quads);
                
                for (int k = 0; k < vertices.Length; ++k)
                {
                    GL.Normal3(normals[k]);
                    if(scene.Materials[mesh.MaterialIndex].HasTextureDiffuse) 
                        GL.TexCoord2(textureCoordinates[k].X, textureCoordinates[k].Y);
                    GL.Vertex3(vertices[k]);
                }

                GL.End();

                GL.EndList();
            }
        }

        private void LoadTextures()
        {
            int meshCount = scene.MeshCount;
            materialLoader = new MaterialLoader();

            for (int i = 0; i < meshCount; i++)
            {
                Mesh mesh = scene.Meshes[i];
                if (mesh.MaterialIndex >= 0)
                {
                    Material material = scene.Materials[mesh.MaterialIndex];
                    materialLoader.LoadMaterialTextures(material);
                }
            }
        }

        public void RenderModel()
        {
            int meshCount = scene.MeshCount;
            for (int i = 0; i < meshCount; i++)
            {
                GL.CallList(displayLists[i]);
            }
        }

        private Vector3[] AssimpVectroToOpenTKVector(Vector3D[] vecArr)
        {
            Vector3[] vector3s = new Vector3[vecArr.Length];

            for(int i = 0; i < vecArr.Length; i++)
            {
                vector3s[i].X = vecArr[i].X;
                vector3s[i].Y = vecArr[i].Y;
                vector3s[i].Z = vecArr[i].Z;
            }

            return vector3s;
        }
    }
}
