package test;

import ej.microui.led.Leds;

public class TestLEDs {

	public static void main(String[] args) throws InterruptedException {
		int n = Leds.getNumberOfLeds();
		while(true){
			for(int i = n; --i>=0;){
				Leds.setLedOn(i);
			}
			Thread.sleep(500);
			for(int i = n; --i>=0;){
				Leds.setLedOff(i);
			}
			Thread.sleep(500);
		}
	}
}
