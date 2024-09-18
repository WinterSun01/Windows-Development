using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Clock
{
    public partial class MainForm : Form
    {
        
        private NotifyIcon trayIcon;

        public MainForm()
        {
            InitializeComponent();

            this.Icon = new Icon("time.ico");

            trayIcon = new NotifyIcon();
            trayIcon.Icon = new Icon("time.ico");
            trayIcon.Text = "Clock Project";
            trayIcon.Visible = true;

            trayIcon.DoubleClick += new EventHandler(trayIcon_DoubleClick);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.ShowIcon = true;
        }

        protected override void OnResize(EventArgs e)
        {
            base.OnResize(e);
            
            if (this.WindowState == FormWindowState.Minimized)
            {
                this.Hide();
                trayIcon.Visible = true;
            }
        }

        
        private void trayIcon_DoubleClick(object sender, EventArgs e)
        {
            this.Show();
            this.WindowState = FormWindowState.Normal;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            label1.Text = DateTime.Now.ToString("HH:mm:ss");

            if (cbShowDate.Checked)
                label1.Text += $"\n{DateTime.Now.ToString("dd.MM.yyyy")}";
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            
        }

        private void label1_Click(object sender, EventArgs e)
        {
            
        }
    }
}
