#include "entity_instancer.h"


namespace zylann::voxel {

EntityInstancer::EntityInstancer() {
    set_notify_transform(true);
    set_process_internal(true);
    // _generator_results = make_shared_instance<VoxelInstancerGeneratorTaskOutputQueue>();
}

EntityInstancer::~EntityInstancer() {

    
}


}