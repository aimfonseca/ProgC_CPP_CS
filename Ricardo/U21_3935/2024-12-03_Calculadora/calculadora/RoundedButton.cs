using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Windows.Forms;

namespace calculadora
{
    public class RoundedButton : Button
    {
        protected override void OnPaint(PaintEventArgs pevent)
        {
            base.OnPaint(pevent);

            // Create a new graphics path to draw the button shape
            GraphicsPath graphicsPath = new GraphicsPath();
            graphicsPath.AddEllipse(0, 0, ClientSize.Width, ClientSize.Height);

            // Set the Region property to the graphics path to change the shape
            this.Region = new Region(graphicsPath);

            // Optional: Customize the button appearance
            // pevent.Graphics.DrawEllipse(new Pen(Color.Black), 0, 0, ClientSize.Width, ClientSize.Height);
        }
    }
}
