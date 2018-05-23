using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using CLR_link;
using System.IO;
namespace Taxi_Trajectories
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        private const int MAX_SHOW = 1000;
        private Class1 ptrCar=new Class1();
        private bool used;
        private String Path;
        private int carNum;
        private bool[] hasShowed;
        public MainWindow()
        {
            InitializeComponent();
            Path = Convert.ToString(Environment.CurrentDirectory);
            Map.Source = new Uri(Path + "\\Bmap.html");
            used = false;
            ptrCar.obtainPath(Path);
            carNum = 0;
            hasShowed = new bool[MAX_SHOW];
            for (int i = 1; i < MAX_SHOW; i++) hasShowed[i] = false;
        }

        private void show(CMetaData[] e, int carId)
        {
            if (hasShowed[carId] == true) return;
            hasShowed[carId] = true;
            for (int i = 0; i < e.Length; i++)
            {
                Map.InvokeScript("addLine", new object[] {e[i].longitude, e[i].dimension});
            }
            Map.InvokeScript("showLine");
        }

        private void Button_Click(object sender, RoutedEventArgs e)//展示按钮
        {
            if (carNum==0)
            {
                MessageBox.Show("未加载文件");
                return;
            }
            CMetaData[] tmp = ptrCar.Traverse(int.Parse(Id.Text));
            if (tmp.Length == 0)
            {
                MessageBox.Show("输入超出范围");
                return;
            }
            MessageBox.Show("添加数据量：" + tmp.Length.ToString());
            show(tmp, int.Parse(Id.Text));
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            if (used == true)
            {
                MessageBox.Show("您已成功加载过，无需再次加载");
            }
            else
            {
                carNum = ptrCar.roadFromFile();
                MessageBox.Show("加载成功，加载文件数为"+carNum);
                used = true;
            }
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)//清空数据
        {
            for (int i = 1; i < MAX_SHOW; i++) hasShowed[i] = false;
            Map.InvokeScript("showClear");
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            if (carNum == 0)
            {
                MessageBox.Show("未加载文件");
                return;
            }
            for (int i=1;i<=carNum;i++)
            {
                CMetaData[] tmp = ptrCar.Traverse(i);
                if (MessageBox.Show("是否暂时第" + i + "辆出租车信息？", "展示", MessageBoxButton.YesNo) == MessageBoxResult.Yes)
                {
                    show(tmp, i);
                }
                else
                {
                    break;
                }                
            }
        }
    }
}
