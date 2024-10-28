#include <vector>
#include <GLFW/glfw3.h>
#include <iostream>
using std::vector;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_move_callback(GLFWwindow* window, double xpos, double ypos);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void display(void);
void Bezier(int n);

const GLuint WIDTH = 800, HEIGHT = 600;

vector<vector<GLfloat>> Points(4, vector<GLfloat>(2));  // Store the x, y coordinates of each vertex
GLfloat mouseX, mouseY; // Mouse position on mouse click
int count = 0;

int main()
{
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Bezier", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_move_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        display();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void mouse_move_callback(GLFWwindow* window, double xpos, double ypos)
{
    mouseX = xpos;
    mouseY = ypos;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        count %= 4;
        Points[count][0] = mouseX * 2 / WIDTH - 1;
        Points[count][1] = (mouseY * 2 / HEIGHT - 1) * -1;
        count++;
    }
}

void display(void)
{
    if (count == 4)
    {
        glBegin(GL_POINTS);
        for (int i = 0; i < count; i++)
        {
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(Points[i][0], Points[i][1]);
        }
        glEnd();
        Bezier(20);
    }
    else
    {
        glBegin(GL_POINTS);
        for (int i = 0; i < count; i++)
        {
            glColor3f(0.0f, 1.0f, 1.0f);
            glVertex2f(Points[i][0], Points[i][1]);
        }
        glEnd();
    }
}

void Bezier(int n)
{
    float f1, f2, f3, f4;
    float deltaT = 1.0 / n;
    float T;
    glBegin(GL_LINE_STRIP);
    glColor3f(0.8f, 0.2f, 0.5f);
    for (int i = 0; i <= n; i++)
    {
        T = i * deltaT;
        f1 = (1 - T) * (1 - T) * (1 - T);
        f2 = 3 * T * (1 - T) * (1 - T);
        f3 = 3 * T * T * (1 - T);
        f4 = T * T * T;
        float x = f1 * Points[0][0] + f2 * Points[1][0] + f3 * Points[2][0] + f4 * Points[3][0];
        float y = f1 * Points[0][1] + f2 * Points[1][1] + f3 * Points[2][1] + f4 * Points[3][1];
        glVertex2f(x, y);
    }
    glEnd();
}