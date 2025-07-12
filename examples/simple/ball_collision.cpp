#include <SFML/Graphics.hpp>
#include <cmath>

constexpr float radius = 30.0f;
constexpr float speed = 200.0f;

//this defines the ball
struct Ball {
    sf::CircleShape shape;
    sf::Vector2f velocity;

    Ball(float x, float y, sf::Vector2f vel) : velocity(vel) {
        shape.setRadius(radius);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(x, y);
    }

    void update(const float dt) {
        shape.move(velocity * dt);
    }
};

//checks if the 2 balls collide
bool checkCollision(const Ball& a, const Ball& b) {
    //gets the difference in position from the circles themselves
    sf::Vector2f diff = a.shape.getPosition() - b.shape.getPosition();

    //calculates the Euclidean distance between their centers and checks if it's less than the radii of both of the balls combined
    const float dist = std::sqrt(diff.x * diff.x + diff.y * diff.y);
    return dist < 2 * radius;
}

//effectively makes the balls bounce off of each other
void makeTheBallsBounce(Ball& a, Ball& b) {
    std::swap(a.velocity, b.velocity);
}

int main() {
    //creates a 800x600 pixel window that will display this simulation
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ball Collision");
    window.setFramerateLimit(60);

    //this makes the 2 ball objects at different positions and opposite velocities
    Ball ball1(100, 100, {speed, speed});
    Ball ball2(500, 300, {-speed, -speed});

    //this will be used with the update function of the ball object for smooth movements by measuring the time elapsed between frames
    sf::Clock clock;

    //main event loop
    //exits the program cleanly when the user closes it
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //this computes the time elapsed since the last frame in seconds
        float dt = clock.restart().asSeconds();

        //this moves the balls based on the velocity and the elapsed time for clean movement based on how fast the program is running
        ball1.update(dt);
        ball2.update(dt);

        //makes the balls bounce off of each other if they collide
        if (checkCollision(ball1, ball2)) {
            makeTheBallsBounce(ball1, ball2);
        }

        //makes the balls bounce off of walls so that they don't go off the screen
        for (Ball* ball : {&ball1, &ball2}) {
            sf::Vector2f pos = ball->shape.getPosition();

            if (pos.x < 0 || pos.x + 2 * radius > 800)
                ball->velocity.x *= -1;

            if (pos.y < 0 || pos.y + 2 * radius > 600)
                ball->velocity.y *= -1;
        }

        //this resets the screen and draws both balls
        window.clear(sf::Color::Black);
        window.draw(ball1.shape);
        window.draw(ball2.shape);
        window.display();
    }
}