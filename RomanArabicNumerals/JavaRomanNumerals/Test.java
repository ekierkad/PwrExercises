public class Test {
	public static void main (String args[]) {
		for (int i=0; i<args.length; i++) {
			try {
				int n = Integer.parseInt(args[i]);
				try {
					String result = RomanArabic.arabic2roman(n);
					System.out.println(args[i]+" = "+result+" w systemie rzymskim.");
				}
				catch (RomanArabicException ex) {
					System.out.println(n+" - liczba spoza zakresu [1,3999]");
				}
			}
			catch (NumberFormatException e) {
				int result_roman;
				try {
					result_roman = RomanArabic.roman2arabic(args[i]);
					System.out.println(args[i]+" = "+result_roman+" w systemie arabskim.");
				}
				catch (RomanArabicException ex) {
					System.out.println(args[i]+" - nie jest poprawne w systemie rzymskim.");
				}
			}
		}
	}
}
