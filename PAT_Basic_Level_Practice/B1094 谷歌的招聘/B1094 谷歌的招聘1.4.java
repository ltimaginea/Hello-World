package google;

import java.util.Scanner;

public class Google {
	public static boolean isPrime(int a)
	{
		if(a<=1) return false;
		int sqr=(int)Math.sqrt(a);
		for(int i=2;i<=sqr;i++)
		{
			if(a%i==0) return false;
		}
		return true;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input=new Scanner(System.in);
		int L,K;
		L=input.nextInt();
		K=input.nextInt();
		String s1,s2;
		s1=input.next();
		for(int i=0;i+K<=L;i++)
		{
			s2=s1.substring(i,i+K);
			if(isPrime(Integer.parseInt(s2))) {
				System.out.print(s2);
				return ;
			}
		}
		System.out.print("404");
		return ;
	}
	

}
