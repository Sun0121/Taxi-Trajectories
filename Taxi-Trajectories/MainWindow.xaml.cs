using CLR_link;
using System;
using System.Windows;
namespace Taxi_Trajectories
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        private const int SPLIT = 500;
        private const int MAX_SHOW = 1000;
        private Class1 ptrCar=new Class1();
        private bool used;
        private String Path;
        private int carNum;
        public MainWindow()
        {
            InitializeComponent();
            Path = Convert.ToString(Environment.CurrentDirectory);
            Map.Source = new Uri(Path + "\\Bmap.html");
            used = false;
            ptrCar.obtainPath(Path);
            carNum = 0;
        }

        private void Show(String strShow)
        {
            return;
        }

        private void Button_Click(object sender, RoutedEventArgs e)//展示按钮
        {
            if (carNum==0)
            {
                MessageBox.Show("未加载文件");
                return;
            }
            if (int.Parse(Id_2.Text) - int.Parse(Id_1.Text) < 0)
            {
                MessageBox.Show("输入超出范围");
                return;
            }
            String str = ptrCar.Traverse(int.Parse(Id_1.Text),int.Parse(Id_2.Text));
            System.IO.File.WriteAllText(@"F:\test.txt", str);
            Map.InvokeScript("showAllLine");
            /*
            int len = str.Length, x = len/SPLIT;
            MessageBox.Show(len.ToString());
            char[] destination = new char[SPLIT];
            for (int i = 0; i < x; i++)
            {
                //MessageBox.Show((i * SPLIT).ToString());
                //MessageBox.Show((i * SPLIT + SPLIT).ToString());
                str.CopyTo(i * SPLIT, destination, 0, SPLIT);
                //destination[SPLIT] = '\0';
                //MessageBox.Show(new string(destination));
                Map.InvokeScript("getString", new object[] { new string(destination) });
            }
            if (len%SPLIT!=0)
            {
                //MessageBox.Show((x * SPLIT).ToString());
                //MessageBox.Show((x * SPLIT + len % SPLIT).ToString());
                char[] des = new char[len % SPLIT];
                str.CopyTo(x * SPLIT, des, 0, len % SPLIT);
                //des[len % SPLIT] = '\0';
                //MessageBox.Show(new string(destination));
                Map.InvokeScript("getString", new object[] { new string(des) });
            }
            Map.InvokeScript("showAllLine");
            Map.InvokeScript("deleteString");
            */
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)//文件加载
        {
            if (used == true)
            {
                MessageBox.Show("您已成功加载过，无需再次加载");
            }
            else
            {
                carNum = ptrCar.roadFromFile();
                MessageBox.Show("加载成功，加载汽车数为"+carNum);
                used = true;
            }
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)//清空数据
        {
            Map.InvokeScript("showClear");
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            if (carNum == 0)
            {
                MessageBox.Show("未加载文件");
                return;
            }
            Show(ptrCar.Traverse(1,10357));
        }
    }
}
