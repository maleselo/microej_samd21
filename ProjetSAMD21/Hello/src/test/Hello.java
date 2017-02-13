package test;

public class Hello {

	public static void main(String[] args) {
		System.out.println("Hello.main()");
		
		long t0 = System.currentTimeMillis();
		while(true){
			long t = System.currentTimeMillis();
			if (t - t0 > 1000){
				System.out.println("Hello.main()");
				t0 = t;
			}
		}
	}
	
	
}
