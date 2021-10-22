// https://developer-old.gnome.org/gtkmm-tutorial/stable/sec-helloworld.html.en

#include "helloworld.hpp"
#include <iostream>

HelloWorld::HelloWorld() 
    : m_button("Hello World") {
    // Sets the margin around the button.
    set_border_width(10);

    // When the button receives the "clicked" signal, it will call
    // the on_button_clicked() method defined below
    m_button.signal_clicked().connect(sigc::mem_fun(*this, &HelloWorld::on_button_clicked));

    // This packs the button into the Window (a container)
    add(m_button);

    m_button.show();
    show();
}


void HelloWorld::on_button_clicked(){
    std::cout << "Hello World" << std::endl;
}