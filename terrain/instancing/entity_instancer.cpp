#include "entity_instancer.h"


namespace zylann::voxel {

EntityInstancer::EntityInstancer() {
    set_notify_transform(true);
    set_process_internal(true);
    // _generator_results = make_shared_instance<VoxelInstancerGeneratorTaskOutputQueue>();
}

EntityInstancer::~EntityInstancer() {

    
}

void EntityInstancer::_bind_methods() {
    
    ClassDB::bind_method(D_METHOD("is_octant_available"), &EntityInstancer::is_octant_available);
    ClassDB::bind_method(D_METHOD("get_octant_transforms"), &EntityInstancer::get_octant_transforms);
    ClassDB::bind_method(D_METHOD("clear_octant"), &EntityInstancer::clear_octant);

}
}