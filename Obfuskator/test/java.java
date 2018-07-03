package rekurencje;
import java.util.Scanner;
public class Silnia {

	public static int TbvMXkD(int IntaEFpZghoP)
	{
	if (IntaEFpZghoP==1) return 1;
	return IntaEFpZghoP*TbvMXkD(IntaEFpZghoP-1);
	}
	
	public static void main(String[] args) {
	Scanner RULlhyfCJ=new Scanner(System.in);
	System.out.print("podaj liczbe do silni: ");
	int IntaEFpZghoP=RULlhyfCJ.nextInt();
	if(IntaEFpZghoP>15) System.out.print("liczba za du¿a!");
	else System.out.print("silnia z "+IntaEFpZghoP+" wynosi: "+TbvMXkD(IntaEFpZghoP));
	RULlhyfCJ.close();

	}

}







