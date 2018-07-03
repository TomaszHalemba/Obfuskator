package rekurencje;
import java.util.Scanner;
public class Silnia {

	public static int silnia(int n)
	{
	if (n==1) return 1;
	return n*silnia(n-1);
	}
	
	public static void main(String[] args) {
	Scanner wpisz=new Scanner(System.in);
	System.out.print("podaj liczbe do silni: ");
	int n=wpisz.nextInt();
	if(n>15) System.out.print("liczba za du¿a!");
	else System.out.print("silnia z "+n+" wynosi: "+silnia(n));
	wpisz.close();

	}

}
