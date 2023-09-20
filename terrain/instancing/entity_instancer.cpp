#include "entity_instancer.h"


namespace zylann::voxel {

EntityInstancer::EntityInstancer() {
    set_notify_transform(true);
    set_process_internal(true);
    // _generator_results = make_shared_instance<VoxelInstancerGeneratorTaskOutputQueue>();
}

EntityInstancer::~EntityInstancer() {

    
}

bool EntityInstancer::is_octant_available(Vector3i octantID) {
	return storage.has(octantID);
}

Vector<float> EntityInstancer::get_octant_transforms(Vector3i octantID) {
	return Vector<float>();
}

int64_t EntityInstancer::get_octant_transforms_direct(int64_t id) {
    if(id >= data->size())
    {
        return 0;
    }
    
	return reinterpret_cast<int64_t>(data[id].ptr());
}

int64_t EntityInstancer::get_octant_transform_array_len(int64_t id) {
    if(id >= data->size())
    {
        return 0;
    }

	return data[id].size();
}

bool EntityInstancer::is_layer_initialized(int64_t id) {
    if(id >= 3)
    {
        return 0;
    }

    return initialized[id];

}

Transform3D EntityInstancer::get_trs_at(int64_t trs_id, int64_t arrayID) {
	if(arrayID >= 3)
    {
        return Transform3D {};
    }
    
    if(trs_id >= data[arrayID].size())
    {
        return Transform3D {};
    }

    return data[arrayID][trs_id];

}

void EntityInstancer::clear_octant(Vector3i octantID) {

    if(storage.has(octantID) == false)
    {
        return;
    }

    storage[octantID].clear();
}

void EntityInstancer::store_transforms_data(Span<const Transform3f> data) {
    
    //mut.lock();
    

    for(int i = 0; i < data.size(); i++)
    {
        Transform3f trs = data[i];
        Vector3i octant;
        octant.x = Math::floor(trs.origin.x / 32);
        octant.y = Math::floor(trs.origin.y / 32);
        octant.z = Math::floor(trs.origin.z / 32);

        if(storage.has(octant) == false)
        {
            storage[octant] = Vector<Transform3D>();
        }

        // Not ideal but hey whaterver
        storage[octant].append(Transform3D(
            trs.basis.rows[0].x,trs.basis.rows[0].y,trs.basis.rows[0].z,
            trs.basis.rows[1].x,trs.basis.rows[1].y,trs.basis.rows[1].z,
            trs.basis.rows[2].x,trs.basis.rows[2].y,trs.basis.rows[2].z,
            trs.origin.x,trs.origin.y,trs.origin.z));
    }

    //mut.unlock();


}

void EntityInstancer::_bind_methods() {
	//ClassDB::bind_method(D_METHOD("is_octant_available"), &EntityInstancer::is_octant_available);
    //ClassDB::bind_method(D_METHOD("get_octant_transforms"), &EntityInstancer::get_octant_transforms);
    //ClassDB::bind_method(D_METHOD("clear_octant"), &EntityInstancer::clear_octant);

    ClassDB::bind_method(D_METHOD("get_octant_transform_array_len", "arrayID"), &EntityInstancer::get_octant_transform_array_len);
    ClassDB::bind_method(D_METHOD("get_octant_transforms_direct", "arrayID"), &EntityInstancer::get_octant_transforms_direct);
    ClassDB::bind_method(D_METHOD("get_trs_at", "trs_id", "arrayID"), &EntityInstancer::get_trs_at);
    ClassDB::bind_method(D_METHOD("is_layer_initialized", "arrayID"), &EntityInstancer::is_layer_initialized);
}
}