using System.Runtime.InteropServices;
namespace ConsoleApp1
{
	internal class Program
	{
		[DllImport("Dll1.dll", CallingConvention = CallingConvention.StdCall)]
		[return: MarshalAs(UnmanagedType.LPStr)]
		static extern string f5(int 値, int 桁数);

		static void Main(string[] args)
		{
			int 桁数;
			if (int.TryParse(System.Console.ReadLine(), out 桁数))
			{
				if (1 <= 桁数 && 桁数 <= 10)
				{
					for (int 値 = 0; ;++値)
					{
						string s = f5(値, 桁数);
						if (s == "")
							break;
						else
							System.Console.WriteLine(s);
					}
				}
			}
		}
	}
}
