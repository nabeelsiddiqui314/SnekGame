#include "stdafx.h"
#include "State.h"

StateManager::StateManager() {
	m_state = new State();
}

void StateManager::SetWindow(sf::RenderWindow& window) {
	m_window = &window;
}

void StateManager::SetState(State* state) {
	delete m_state;
	m_state = state;
}

void StateManager::Update() {
	m_state->HandleInput(*m_window);
	m_state->Update(*m_window);
}

void StateManager::Render() {
	m_state->Render(*m_window);
}

StateManager::~StateManager() {
	delete m_state;
}