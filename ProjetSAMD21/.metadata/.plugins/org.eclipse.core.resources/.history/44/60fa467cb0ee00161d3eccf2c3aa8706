package test;

import ej.microui.MicroUI;
import ej.microui.display.Colors;
import ej.microui.display.Display;
import ej.microui.display.Displayable;
import ej.microui.display.GraphicsContext;
import ej.microui.util.EventHandler;

public class TestLCD01 extends Displayable{

	public TestLCD01(Display display) {
		super(display);
	}

	public static void main(String[] args) {
		System.out.println("Before MicroUI start");
		MicroUI.start();
		System.out.println("MicroUI started");
		TestLCD01 t = new TestLCD01(Display.getDefaultDisplay());
		System.out.println("LCD declared");
		t.show();
	}

	@Override
	public void paint(GraphicsContext g) {
		
		g.setColor(Colors.WHITE);
		System.out.println("Set color white");
		g.fillRect(0, 0, g.getClipWidth(), g.getClipHeight());
		g.setColor(Colors.BLACK);
		g.drawString("SAMD21", g.getClipWidth() / 2, g.getClipHeight() / 2, GraphicsContext.HCENTER | GraphicsContext.VCENTER);
		System.out.println("Write SAMD21");
	}

	@Override
	public EventHandler getController() {
		// TODO Auto-generated method stub
		return null;
	}
	
}
