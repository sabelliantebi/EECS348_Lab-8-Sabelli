BUILD_DIR = build

all:
	@cmake -S . -B $(BUILD_DIR)
	@cmake --build $(BUILD_DIR)

run-tests:
	@./$(BUILD_DIR)/tests/tests

clean:
	@rm -rf $(BUILD_DIR)