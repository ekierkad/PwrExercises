public class RomanArabic {
	private static String[] romanNumbers = 
		{ "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
	private static int[] arabicValues = 
		{ 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
	
	public static String arabic2roman (int arabic) {
		String roman = "";
		int pointer = 12;
		while (arabic > 0) {
			if (RomanArabic.arabicValues[pointer]<=arabic) {
				roman += RomanArabic.romanNumbers[pointer];
				arabic-=RomanArabic.arabicValues[pointer];
			}
			else {
				pointer-=1;
			}
		}
		return roman;
	}
}