#ifndef MINISIM_ROOTDIRECTORY_H
#define MINISIM_ROOTDIRECTORY_H

#include <filesystem>
#include <memory>
#include <mutex>
#include <string>
#include <string_view>

// Create a singleton to store the Root Directory
class RootDirectory {
   public:
	RootDirectory(RootDirectory& other) = delete;
	RootDirectory& operator=(const RootDirectory& other) = delete;
	RootDirectory(RootDirectory&& other) = delete;
	RootDirectory& operator=(RootDirectory&& other) = delete;
	~RootDirectory() = default;

	void set_root_directory(std::string_view new_root_directory);
	std::string get_root_directory() const;
	std::string prepend_root_directory(std::string_view path) const;
	std::string remove_root_directory_from(std::string_view path) const;

	static RootDirectory* get_instance() {
		static RootDirectory instance;
		return &instance;
	}

   private:
	RootDirectory() : root_directory("/Users/swesikramineni/github/solarcar/solarcar-training-p2") {}
	std::mutex root_directory_mutex;
	std::filesystem::path root_directory;
};

std::string get_root_directory();
std::string normalize_path(std::string_view path);

std::string remove_root_directory_from(std::string_view path);
void set_root_directory(std::string_view new_root_directory);

#endif  // SOLAR_CAR_SIMULATOR_ROOTDIRECTORY_H
