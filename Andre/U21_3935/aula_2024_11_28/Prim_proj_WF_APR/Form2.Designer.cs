namespace Prim_proj_WF_APR
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Button0 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            //
            // Button0
            //
            this.Button0.Text =  "Voltar";
            this.Button0.Location = new System.Drawing.Point(144,144);
            this.Button0.Size = new System.Drawing.Size(184,48);
         //
         // form
         //
            this.Size = new System.Drawing.Size(480,400);
            this.Text =  "Form1";
            this.Controls.Add(this.Button0);
            this.ResumeLayout(false);
        } 

        #endregion 

        private System.Windows.Forms.Button Button0;
    }
}

