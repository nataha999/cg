using Assimp;
using OpenTK.Graphics.OpenGL;
using OpenTK;
using OpenTK.Windowing.Common;
using OpenTK.Windowing.Desktop;
using OpenTK.Mathematics;
using OpenTK.Windowing.GraphicsLibraryFramework;
using System.Timers;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using Timer = System.Timers.Timer;
using System.Threading;

namespace _1
{
    internal class Chess
    {
        Model rook;
        Model knight;
        Model bishop;
        Model queen;
        Model king;
        Model pawn;
        Model board;

        //Timer timer;

        Color4 blackColor = new Color4(0.2f, 0.2f, 0.2f, 1f);
        float quadSize = 40f;


        public Chess() 
        {
            //timer = new Timer();
            //timer.Interval = 100;
            //timer.Elapsed += Timer_Elapsed;
            //timer.Start();

            rook = new Model();
            rook.LoadModel("models/Rook.obj");

            knight = new Model();
            knight.LoadModel("models/Knight.obj");

            bishop = new Model();
            bishop.LoadModel("models/Bishop.obj");

            queen = new Model();
            queen.LoadModel("models/Queen.obj");

            king = new Model();
            king.LoadModel("models/King.obj");

            pawn = new Model();
            pawn.LoadModel("models/Pawn.obj");

            board = new Model();;
            board.LoadModel("models/ChessBoard.obj");
        }

        //private void Timer_Elapsed(object? sender, ElapsedEventArgs e)
        //{
        //    //Console.WriteLine("Таймер сработал: " + DateTime.Now);
        //}

        public void Draw()
        {
            DrawBoard();

            GL.PushMatrix();
            GL.Translate(0f, 20f, 0f);
            GL.Rotate(-90f, 1f, 0f, 0f);

            DrawWhiteRooks();
            DrawBlackRooks();

            DrawWhiteKhights();
            DrawBlackKhights();

            DrawWhiteBishops();
            DrawBlackBishops();

            DrawKings();
            DrawQueens();

            DrawPawns();

            GL.PopMatrix();

        }

        private void DrawKings()
        {
            GL.PushMatrix();
            GL.Translate(quadSize / 2, -(quadSize * 3 + quadSize / 2), 0f);
            GL.Color4(Color4.White);
            king.RenderModel();
            GL.PopMatrix();

            GL.PushMatrix();
            GL.Translate(quadSize / 2, (quadSize * 3 + quadSize / 2), 0f);
            GL.Color4(blackColor);
            king.RenderModel();
            GL.PopMatrix();
        }

        private void DrawQueens()
        {
            GL.PushMatrix();
            GL.Translate(-(quadSize / 2), -(quadSize * 3 + quadSize / 2), 0f);
            GL.Color4(Color4.White);
            queen.RenderModel();
            GL.PopMatrix();

            GL.PushMatrix();
            GL.Translate(-(quadSize / 2), (quadSize * 3 + quadSize / 2), 0f);
            GL.Color4(blackColor);
            queen.RenderModel();
            GL.PopMatrix();
        }

        private void DrawBoard()
        {
            GL.PushMatrix();
            GL.Scale(90f, 90f, 90f);
            GL.Color4(Color4.White);
            board.RenderModel();
            GL.PopMatrix();
        }

        private void DrawWhiteRooks()
        {
            GL.PushMatrix();
            GL.Translate(quadSize * 3 + quadSize / 2, -(quadSize * 3 + quadSize / 2), 0f);
            GL.Color4(Color4.White);
            rook.RenderModel();
            GL.PopMatrix();

            GL.PushMatrix();
            GL.Translate(-(quadSize * 3 + quadSize / 2), -(quadSize * 3 + quadSize / 2), 0f);
            GL.Color4(Color4.White);
            rook.RenderModel();
            GL.PopMatrix();
        }

        private void DrawBlackRooks()
        {
            GL.PushMatrix();
            GL.Translate(quadSize * 3 + quadSize / 2, (quadSize * 3 + quadSize / 2), 0f);
            GL.Color4(blackColor);
            rook.RenderModel();
            GL.PopMatrix();

            GL.PushMatrix();
            GL.Translate(-(quadSize * 3 + quadSize / 2), (quadSize * 3 + quadSize / 2), 0f);
            GL.Color4(blackColor);
            rook.RenderModel();
            GL.PopMatrix();
        }

        private void DrawWhiteKhights()
        {
            GL.PushMatrix();
            GL.Translate(quadSize * 2 + quadSize / 2, -(quadSize * 3 + quadSize / 2), 0f);
            GL.Rotate(180f, 0f, 0f, 1f);
            GL.Color4(Color4.White);
            knight.RenderModel();
            GL.PopMatrix();

            GL.PushMatrix();
            GL.Translate(-(quadSize * 2 + quadSize / 2), -(quadSize * 3 + quadSize / 2), 0f);
            GL.Rotate(180f, 0f, 0f, 1f);
            GL.Color4(Color4.White);
            knight.RenderModel();
            GL.PopMatrix();
        }

        private void DrawBlackKhights()
        {
            GL.PushMatrix();
            GL.Translate(quadSize * 2 + quadSize / 2, (quadSize * 3 + quadSize / 2), 0f);
            GL.Color4(blackColor);
            knight.RenderModel();
            GL.PopMatrix();

            GL.PushMatrix();
            GL.Translate(-(quadSize * 2 + quadSize / 2), (quadSize * 3 + quadSize / 2), 0f);
            GL.Color4(blackColor);
            knight.RenderModel();
            GL.PopMatrix();
        }

        private void DrawWhiteBishops()
        {
            GL.PushMatrix();
            GL.Translate(quadSize + quadSize / 2, -(quadSize * 3 + quadSize / 2), 0f);
            GL.Color4(Color4.White);
            bishop.RenderModel();
            GL.PopMatrix();

            GL.PushMatrix();
            GL.Translate(-(quadSize + quadSize / 2), -(quadSize * 3 + quadSize / 2), 0f);
            GL.Color4(Color4.White);
            bishop.RenderModel();
            GL.PopMatrix();
        }

        private void DrawBlackBishops()
        {
            GL.PushMatrix();
            GL.Translate(quadSize + quadSize / 2, (quadSize * 3 + quadSize / 2), 0f);
            GL.Color4(blackColor);
            bishop.RenderModel();
            GL.PopMatrix();

            GL.PushMatrix();
            GL.Translate(-(quadSize + quadSize / 2), (quadSize * 3 + quadSize / 2), 0f);
            GL.Color4(blackColor);
            bishop.RenderModel();
            GL.PopMatrix();
        }

        private void DrawPawns()
        {

            for (int i = -4; i < 4; i++)
            {
                GL.PushMatrix();
                GL.Translate(i * quadSize + quadSize / 2, (quadSize * 2 + quadSize / 2), 0f);
                GL.Color4(blackColor);
                pawn.RenderModel();
                GL.PopMatrix();
            }

            for (int i = -4; i < 4; i++)
            {
                GL.PushMatrix();
                GL.Translate(i * quadSize + quadSize / 2, -(quadSize * 2 + quadSize / 2), 0f);
                GL.Color4(Color4.White);
                pawn.RenderModel();
                GL.PopMatrix();
            }

        }

    }
}
