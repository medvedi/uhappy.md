<?php
/**
 * @file
 * uhappy_ct.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhappy_ct_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_children_settings|node|scenario|form';
  $field_group->group_name = 'group_children_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'scenario';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Children settings',
    'weight' => '7',
    'children' => array(
      0 => 'field_age_range',
      1 => 'field_children_categories',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-children-settings field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_children_settings|node|scenario|form'] = $field_group;

  return $export;
}
