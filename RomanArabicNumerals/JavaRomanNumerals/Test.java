public class Test{
	public static void main (String args[]) {
		for (int i=0; i<args.length; i++) {
			try {
				int n = Integer.parseInt(args[i]);
				System.out.println(args[i]+" = "+RomanArabic.arabic2roman(n)+" in roman.");
			}
			catch (NumberFormatException e) {
				System.out.println(args[i]+" is not an integer.");
			}
		}
	}
}