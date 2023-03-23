# ESP32 FaerFly - Firmware README

## Concept and Initial Ideas

The brief is to design a light show, with wireless communication between devices to sync colours and patterns.

## Operational Modes
_More can be added as time goes on_

1. Known Starting Position into Randomness

Lightshow starts from a given frame, and then over time random elements are added. This will be easy to coordinate wirelessly, as the _leader_ simply has to 
transmit a starting point for the lightshow, then over t(time) the follower units can add their own random elements. This will look striking as elements will
seem to sync up then drift apart over time. The dataframe could contain the following information:

1. Colour 1*
2. Colour 2
3. Colour 3
4. Colour 4
5. Movement Pattern(s)
6. transition time (i.e. transition time set to 0 would update all followers instantly, wheres setting a transition of a few seconds to minuites would create the effect of the elements slowly drifting together and apart again.
7. brightness
8. time t to start introducing random elements
9. accelleration, how quickly to ramp up random elements

*Note colours could themselves be predefined pallets containing several colours

The advantage of this topology is all of these parameters can be coded into the leader for testing, and then would need just 1 dataframe between leader and followers to act.

## Development Map

1. Develop the single lightshow for the leader, using basic colours, movement and brightness
2. Introduce random elements over time
3. Change the speed of changes of random elements (accelleration)
4. introduce delay before adding random elements
5. Start development of wireless dataframe transmission
6. Start development of wireless dataframe reception
7. add additional animation elements, movements, fades & pulses
8. Add support for palettes as well as single colours.

- At this point this operational mode should be complete.
