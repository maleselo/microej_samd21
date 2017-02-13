package test;

import ej.microui.MicroUI;
import ej.microui.display.Colors;
import ej.microui.display.Display;
import ej.microui.display.Displayable;
import ej.microui.display.GraphicsContext;
import ej.microui.util.EventHandler;

public class TestLCD03 extends Displayable{

	private static final long SLEEP = 1000;
private int cpt;	// 0 init
private int color;
	
	public TestLCD03(Display display) {
		super(display);
		color = Colors.WHITE;
	}

	public static void main(String[] args) throws InterruptedException {
		MicroUI.start();
		TestLCD03 t = new TestLCD03(Display.getDefaultDisplay());
		t.show();
		
		while(t.cpt < 16){
			if (SLEEP > 0){
				Thread.sleep(SLEEP);
			}
				
			t.repaint();
		}
	}

	@Override
	public void paint(GraphicsContext g) {
		color = color == Colors.WHITE ? Colors.BLACK : Colors.WHITE;
		g.setColor(color);
		g.fillRect(cpt, cpt, g.getClipWidth() - cpt *2 , g.getClipHeight()-cpt*2);
		cpt += 1;
		
	}

	@Override
	public EventHandler getController() {
		// TODO Auto-generated method stub
		return null;
	}
	
}
