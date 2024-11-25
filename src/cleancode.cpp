#include <functional>
#include <unordered_map>
#include <iostream>
#include <memory>

using namespace std;

// Abstract base class for Jobs
class Job {
public:
	virtual ~Job() = default;
	virtual bool run() = 0;
};

// Concrete Job implementations
class Spin: public Job {
public:
	bool run() override {
		cout << "Spin";
		return true;
	}
};

class Slide: public Job {
public:
	bool run() override {
		cout << "Slide";
		return true;
	}
};

class Hop: public Job {
public:
	bool run() override {
		cout << "Hop";
		return true;
	}
};

// Job Factory
class JobFactory {
public:
	using JobCreator = function<unique_ptr<Job>()>;

	static JobFactory& getInstance() {
		static JobFactory instance;
		return instance;
	}

	void registerJob(unsigned int type, JobCreator creator) {
		creators[type] = creator;
	}

	unique_ptr<Job> createJob(unsigned int type) const {
		auto it = creators.find(type);
		if (it != creators.end()) {
			return it->second();
		} else {
			throw runtime_error("Unknown job type");
		}
	}

private:
	unordered_map<unsigned int, JobCreator> creators;

	JobFactory() = default;
	~JobFactory() = default;

	// Disallow copying and assigning
	JobFactory(const JobFactory&) = delete;
	JobFactory& operator=(const JobFactory&) = delete;
};

// Icon class using the JobFactory to create Jobs
class Icon {
public:
	Icon(unsigned value) :
			subtype(value) {
	}

	bool move() {
		return JobFactory::getInstance().createJob(subtype)->run();
	}

	bool flair() {
		return JobFactory::getInstance().createJob(subtype)->run();
	}

private:
	unsigned subtype;
};

void registerJobs(JobFactory& factory) {
    factory.registerJob(1, []() { return make_unique<Spin>(); });
    factory.registerJob(2, []() { return make_unique<Slide>(); });
    factory.registerJob(3, []() { return make_unique<Hop>(); });
}

int main() {
	JobFactory& factory = JobFactory::getInstance();
	    registerJobs(factory);

	Icon icon(2);
	icon.move();
	icon.flair();
	return 0;
}
