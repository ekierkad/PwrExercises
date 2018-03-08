public class RomanArabic {
	private static String[] romanNumbers = 
		{ "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
	private static int[] arabicValues = 
		{ 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
	
	public static String arabic2roman (int arabic) throws RomanArabicException {
		if (arabic<=0 || arabic>3999) {
			throw new RomanArabicException();
		}
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
	
	public static int roman2arabic (String roman) throws RomanArabicException {
		int pointer=0;
		int arabic=0;
		boolean is_found;
		String current;
		while (pointer<roman.length()) {
			is_found = false;
			if (roman.length()-pointer>1) {
				current = Character.toString(roman.charAt(pointer))+Character.toString(roman.charAt(pointer+1));
				for (int i=0; i<=12; i++) {
					if (current.equals( RomanArabic.romanNumbers[i])) {
						arabic += RomanArabic.arabicValues[i];
						pointer+=2;
						is_found=true;
						break;
					}
				}
				if (is_found) {
					continue;
				}
			}
			current = Character.toString(roman.charAt(pointer));
			for (int i=0; i<=12; i++) {
				if (current.equals( RomanArabic.romanNumbers[i])) {
					arabic+=RomanArabic.arabicValues[i];
					pointer+=1;
					is_found=true;
				}
			}
			if (is_found==false) {
				throw new RomanArabicException();
			}			
		}
		if (roman.equals(RomanArabic.arabic2roman(arabic))) {
			return arabic;
		}
		else {
			throw new RomanArabicException();
		}
	}
}




