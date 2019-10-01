public class SmartPowers
{
	//a simple and quick algorithm to raise a number to an integer power
	public double raiseToPower(double base, int exponent)
	{
		double accumPow = 1;
		double pow = base;
		
		while(exponent > 1)
		{
			if(exponent % 2 == 1)
			{
				accumPow *= pow;
			}
			exponent /= 2;
			pow *= pow;
		}
		pow *= accumPow;
		return pow;
	}
}
