using System.Runtime.InteropServices;
namespace ConsoleApp1
{
	internal class Program
	{
		[DllImport("Dll1.dll", CallingConvention = CallingConvention.StdCall)]
		[return: MarshalAs(UnmanagedType.BStr)]
		static extern string f([MarshalAs(UnmanagedType.LPWStr)]string s);
		[DllImport("Dll1.dll", CallingConvention = CallingConvention.StdCall)]
		[return: MarshalAs(UnmanagedType.BStr)]
		static extern string f3([MarshalAs(UnmanagedType.LPStr)] string s);
		[DllImport("Dll1.dll", CallingConvention = CallingConvention.StdCall)]
		[return: MarshalAs(UnmanagedType.BStr)]
		static extern string f4([MarshalAs(UnmanagedType.LPWStr)] string s);
		static void Main(string[] args)
		{
			string s = f4("テスト用の文字列");
			System.Console.WriteLine(s);
		}
	}
}
