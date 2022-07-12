import org.junit.jupiter.api.Test;


import javax.sound.sampled.LineUnavailableException;

import static org.junit.jupiter.api.Assertions.*;

class LineTest {

    @Test
    void testGetSlopeShouldReturnArithmeticException() {
        Line l = new Line(2,4,2,4);
        assertThrows(ArithmeticException.class , () -> {l.getSlope();} );
    }

    @Test
    void testGetSlopeShouldReturnOne() {
        Line l = new Line(1,3,2,4);
        assertEquals(1 , l.getSlope() );
    }

    @Test
    void testGetSlopeShouldReturnSomething() {
        Line l = new Line(14,1,5,26);
        assertTrue(-2.7 - l.getSlope() < 0.1 );
    }

    @Test
    void testGetDistanceShouldReturnOne() {
        Line l = new Line(1 ,1,2,2);
        assertTrue(Math.abs( 1.4 - l.getDistance()) < 0.1);
    }

    @Test
    void testGetDistanceShouldReturnSomething() {
        Line l = new Line(5 ,24,24 ,12);
        assertTrue(Math.abs(22.4 - l.getDistance() ) < 0.1);
    }





}