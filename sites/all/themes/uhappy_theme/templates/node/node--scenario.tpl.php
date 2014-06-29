<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> base-two-col-nodes clearfix"<?php print $attributes; ?>>

  <?php
  // We hide the comments and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  hide($content['field_main_image']);
  hide($content['field_image_list']);
  ?>

  <div class="row">
    <div class="left col-sm-4 col-xs-12">
      <?php print render($content['field_main_image']); ?>
      <?php print render($content['field_image_list']); ?>
    </div>
    <div class="right col-sm-8 col-xs-12">
      <?php if ($title_prefix || $title_suffix || $display_submitted || !$page && $title): ?>
        <header>
          <?php print render($title_prefix); ?>
          <?php if (!$page && $title): ?>
            <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
          <?php endif; ?>
          <?php print render($title_suffix); ?>

          <?php if ($display_submitted): ?>
            <p class="submitted">
              <?php print $user_picture; ?>
              <?php print $submitted; ?>
            </p>
          <?php endif; ?>

          <?php if ($unpublished): ?>
            <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
          <?php endif; ?>
        </header>
      <?php endif; ?>

      <?php if (!empty($field_custom_html)): ?>
        <?php print render($content['field_custom_html']); ?>
      <?php else: ?>
        <?php print render($content['field_categories']); ?>

        <?php if (!empty($field_children_categories)): ?>
          <?php print render($content['field_children_categories']); ?>
        <?php endif; ?>

        <?php if (!empty($field_age_range)): ?>
          <?php print render($content['field_age_range']); ?>
        <?php endif; ?>

        <?php print render($content['body']); ?>

        <?php if (!empty($field_list_of_games_and_competit)): ?>
          <?php print render($content['field_list_of_games_and_competit']); ?>
        <?php endif; ?>

        <?php if (!empty($field_price_for_1_person)): ?>
          <?php print t('Price') . ' ' . render($content['field_price_for_1_person']); ?>
        <?php endif; ?>

        <?php if (!empty($field_price_for_2_person)): ?>
          <?php print render($content['field_price_for_2_person']); ?>
        <?php endif; ?>
      <?php endif; ?>

    </div>
  </div>

  <?php print render($content['comments']); ?>

  <!-- Order popup link -->
  <?php print $order_link ?>

  <!-- Site phone description -->
  <?php if (isset($site_phone_description)): ?>
    <?php print $site_phone_description ?>
  <?php endif; ?>

  <!-- Site phone -->
  <?php if (isset($site_phone)): ?>
    <?php print $site_phone ?>
  <?php endif; ?>

</article>
